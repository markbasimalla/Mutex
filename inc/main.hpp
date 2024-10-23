#include <opencv2/opencv.hpp>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <cstdio>
#include "logger.h"
#include "log_levels.h"
#include "log_config.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <cstring>


using namespace std;
using namespace cv;
#define BUFFER_SIZE 10

void *Running_belt(void *arg);
void *Activate_motor(void *arg);

