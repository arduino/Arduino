/*
 * TurtleBot.h - Library for easy control of an Arduino Uno powered
 * Parallax BoE (Board of Education) robot.
 *
 * License:  Released into the public domain.
 * Authors:
 *   AD:  Andrew C. Dassing
 * Change Log:
 *   2014-03-06 AD:  Conceptualized and initiated.
 */
#ifndef _BoeBot_H_
#define _BoeBot_H_

#include <Servo.h>

class BoEBot {

public:
	BoEBot();
	BoEBot(const int leftMotorPin, const int rightMotorPin,
			const float wheelDiameter, const float axleTrack);
	~BoEBot();

	BoEBot& stop();
	BoEBot& forward(const float revolutions);
	BoEBot& backward(const float revolutions);

	BoEBot& turnLeft();	// 90 degrees
	BoEBot& turnLeft(const float degrees);
	BoEBot& turnRight();   // 90 degrees
	BoEBot& turnRight(const float degrees);

	BoEBot& spinLeft();  // 90 degrees
	BoEBot& spinLeft(const float degrees);
	BoEBot& spinRight(); // 90 degrees

	/*
	 * spinRight(degrees) - spins in place clockwise approximately the number of degrees specified.
	 *
	 * @param degrees the number of degrees to spin clockwise.
	 *
	 * @author A.C. Dassing
	 */
	BoEBot& spinRight(const float degrees);

	void steer(const float speed);

	void setRevolutionsPerSecond(const float revPerSec);

	static const int LeftFullFwdPWM = 1700;
	static const int LeftStopPWM = 1500;
	static const int LeftFullRevPWM = 1300;

	static const int RightFullFwdPWM = 1300;
	static const int RightStopPWM = 1500;
	static const int RightFullRevPWM = 1700;

	static const float SteerSpinLEFT = -200.0;
	static const float SteerTurnLEFT = -100.0;
	static const float SteerFORWARD = 0.0;
	static const float SteerTurnRIGHT = +100.0;
	static const float SteerSpinRIGHT = +200.0;

private:
	void init();
	void engage(const float revolutions);
	long getMsForRevolutions (const float revolutions);
	float getTurnRevsForDegrees(const float degrees);
	float getSpinRevsForDegrees(const float degrees);

	Servo left;
	Servo right;

	float revPerMs;

	float steering;

	int leftMotorPin;
	int leftPwm;

	int rightMotorPin;
	int rightPwm;

	float wheelDiameter; //cm
	float axleTrack;  //cm
	float speed;  // rotations/sec
};

#endif /* _BoeBot_H_ */
