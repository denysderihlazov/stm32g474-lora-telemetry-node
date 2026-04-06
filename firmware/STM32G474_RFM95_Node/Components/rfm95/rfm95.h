#ifndef RFM95_H
#define RFM95_H

#define DEVICE_MODE_TX 1
#define DEVICE_MODE_RX 0

// initially TX
#define DEVICE_MODE DEVICE_MODE_TX

struct RFM95_Config {
	int frequency;
	int power;
	int spreading_factor;
};

#endif // RFM95_H
