#include <stdio.h>

int crossc2_entry(int argc, char **argv) {
    char *tempRes[] = {"(ICMP) Target '172.16.251.211' is alive. [read 8 bytes]",
            "(ICMP) Target '172.16.251.212' is alive. [read 8 bytes]",
            "(ICMP) Target '172.16.251.217' is alive.",
            "(ICMP) Target '172.16.251.219' is alive. [read 8 bytes]",
            "172.16.251.211:445 (platform: 500 version: 6.1 name: HAAAC-PC domain: WORKGROUP)",
            "172.16.251.212:445 (platform: 500 version: 6.0 name: C00101201 domain: test_domain.org)",
            "172.16.251.213:80 (Open-SSH-2.0,1)",
            "172.16.251.214:8001 (Apache Tomcat - Facebook)",
            "172.16.251.215:8002 (Nginx - 404 Not found)",
            "172.16.251.216:8003 (Tomcat - test's blog)",
            "172.16.251.217:8004 (Nginx - bing 搜索)",
            "172.16.251.218:8005 (MySQL - 5.7.14)",
            "172.16.251.219:8004 (tomcat - bing 検索する)",
            "172.16.251.221:8004 (tomcat - bing 검색)",
            "172.16.251.222:8004 (tomcat - bing Поиск дома)",
            "172.16.251.223:8004 (tomcat - bing ค้นหาหน้าแรก)",
            "172.16.251.220:22 (Open-SSH-2.0,1)",
            "172.16.251.221:22 (Open-SSH-2.0,1)"
    };
    for (int i = 0; i < (sizeof(tempRes)/sizeof(char *)); ++i) {
        printf("%s\n", tempRes[i]);
    }
    
    return 1;
}
