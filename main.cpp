// producer main.cpp : 定义控制台应用程序的入口点。
#include <cstring>
#include "CKafkaProducer.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    int ret = 0;
    CKafkaProducer kp;

    char topic[] = "test";
    char brokers[] = "192.168.8.24:9092";
    int partition = 0;

    ret = kp.init(topic, brokers, partition);
    if (ret != 0) {
        printf("Error: kp.init(): ret=%d;\n", ret);
        return 0;
    }

    char buf[1024];
    char str_msg[] = "Hello Kafka ";
    for (int i = 0; i < 10000; i++) {
        memset(buf, 0, sizeof(buf));
        snprintf(buf, sizeof(buf), "%s%d", str_msg, i);
        ret = kp.sendMessage(buf, strlen(buf)); //向kafka服务器发送消息
        if (ret != 0) {
            printf("Error: kp.sendMessage(): ret=%d;\n", ret);
            return 0;
        }
        //sleep(1);
    }

    return 0;
}