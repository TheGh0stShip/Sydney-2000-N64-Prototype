#ifndef SYDNEY2000_AUDIO_RECORD_H
#define SYDNEY2000_AUDIO_RECORD_H

typedef unsigned int AudioRecordWord;

typedef struct AudioRecord {
    AudioRecordWord active;
    AudioRecordWord enabled;
    AudioRecordWord special;
    AudioRecordWord initialized;
    AudioRecordWord value;
    AudioRecordWord volume;
    AudioRecordWord limit;
    AudioRecordWord elapsed;
    AudioRecordWord specialValue;
    AudioRecordWord index;
    AudioRecordWord counter;
    AudioRecordWord owner;
    AudioRecordWord state;
    AudioRecordWord handle;
    AudioRecordWord padding[2];
} AudioRecord;

#endif
