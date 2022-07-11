#include <stdio.h>
#include <mosquitto.h>
#include <memory>
#include <chrono>
#include <thread>
#include <condition_variable>
#include <iostream>

int main(){
	int rc;
	struct mosquitto * mosq;
	char *host = "10.42.0.173";
	int port = 1883;
	int keepalive= 60;
	using Job = void (*)();
	int time=30;
	mosquitto_lib_init();

	mosq = mosquitto_new("publisher-test", true, NULL);
	rc = mosquitto_connect(mosq,"localhost",1883,60);
	// rc = mosquitto_connect(mosq,host,port,keepalive);
	if(rc != 0){
		printf("Client could not connect to broker! Error Code: %d\n", rc);
		mosquitto_destroy(mosq);
		return -1;
	}
	printf("We are now connected to the broker!\n");

	mosquitto_publish(mosq, NULL, "test/t1", 6, "Hello", 0, false);

	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);

	mosquitto_lib_cleanup();
	// .............
	// void schedule(Job mosquitto_publish, int time)
	// {
	// 	std::unique_lock<std::mutex> lock(this->mutex);
    // 	condition.wait(lock, [this] { return this->count < this->size; });
    // 	count++;
	// auto job = std::make_shared<Job>(mosquitto_publish());
    // }
	// scheduler(mosquitto_publish,30);
	// ............
	return 0;
}