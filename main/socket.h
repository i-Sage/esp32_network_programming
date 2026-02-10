#pragma once

#include "includes.h"

void send_msg()
{
    char *server_ip   = "192.168.84.131";
    char *msg         = "esp_32";

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;

    /// convert address
    int rtn_value = inet_pton(AF_INET, server_ip, &serv_addr.sin_addr.s_addr);
    serv_addr.sin_port = htons(60000);

    /// Establish connection
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    uint32_t msg_len = strlen(msg);

    /// send the string to the server
    ssize_t num_bytes = send(sock, msg, msg_len, 0);

    /// receive the same string back
    char buffer[512];
    num_bytes = recv(sock, buffer, 511, 0);
    buffer[num_bytes] = '\0';
    printf("recv -> %s\n", buffer);

    /// close socket
    close(sock);

}