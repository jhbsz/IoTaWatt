#pragma once

#include "IotaWatt.h"
#include "xbuf.h"

struct influxTag {
  influxTag* next;
  char*      key;
  char*      value;
  influxTag()
    :next(nullptr)
    ,key(nullptr)
    ,value(nullptr)
    {}
  ~influxTag(){
    delete[] key;
    delete[] value;
    delete   next;
  }
};

uint32_t influxService(struct serviceBlock* _serviceBlock);
bool influxConfig(JsonObject& config);

extern bool     influxStarted;                    // set true when Service started
extern bool     influxStop;                       // set true to stop the Service
extern bool     influxInitialize;                 // Initialize or reinitialize
extern String   influxURL;
extern uint16_t influxBulkSend;
extern uint16_t influxPort;
extern String   influxDataBase;
extern char*    influxMeasurement;
extern char*    influxUser;
extern char*    influxPwd;
extern influxTag* influxTagSet;  
extern ScriptSet* influxOutputs;