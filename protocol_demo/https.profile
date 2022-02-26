http-get {

    set uri "/aaaaaaaaa";
    set verb "GET";

    client {

        header "Accept" "accccccc";
        header "Host" "www.google.com";
        header "Referer" "http://www.google.com/";
        header "Accept-Encoding" "gzip, deflate";

        metadata {
            base64url;
            prepend "SESSION=";
            header "Cookie";
        }
    }

    server {

        header "Server" "nginx";
        header "Cache-Control" "max-age=0, no-cache";
        header "Pragma" "no-cache";
        header "Connection" "keep-alive";
        header "Content-Type" "charset=utf-8";

        output {
            base64;
            prepend "ffffffff1";
            append "eeeeeeee2";
            print;
        }
    }
}


http-post {

    set uri "/bbbbbbbbb";
    set verb "POST";

    client {

        header "Accept" "accccccc";
        header "Host" "www.google.com";
        header "Referer" "http://www.google.com/";
        header "Accept-Encoding" "gzip, deflate";

        id {
            base64;
            parameter "SESSION";
        }

        output {
            base64url;
            print;
        }
    }

    server {

        header "Server" "nginx";
        header "Cache-Control" "max-age=0, no-cache";
        header "Pragma" "no-cache";
        header "Connection" "keep-alive";
        header "Content-Type" "charset=utf-8";

        output {
            mask;
            base64url;
            prepend "ffffffff1";
            append "eeeeeeee2";
            print;
        }
    }
}
