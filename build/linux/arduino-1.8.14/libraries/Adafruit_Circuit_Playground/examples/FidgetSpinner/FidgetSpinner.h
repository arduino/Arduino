// Fidget spinner logic.
// This class represents a fidget spinner that can be spun to a specified
// velocity and then over time will slow down and stop.  The spinner keeps track
// of its continuous (floating point) position value within the range 0...<10
// so it can map to CircuitPlayground pixel positions easily.// Author: Tony DiCola
// License: MIT License (https://opensource.org/licenses/MIT)
// Usage:
// - Create an instance of the class (specifying a custom decay value between 0 and 1,
//   the lower the decay the faster the spinner slows down).
// - Call spin to start the spinner moving at the specified velocity (in pixels/second).
// - Call getPosition periodically to get the current spinner position given an elapsed
//   amount of seconds since the last getPosition call.
#ifndef FIDGETANIMATION_H
#define FIDGETANIMATION_H

class FidgetSpinner {
public:
  FidgetSpinner(float decay=0.5):
    _position(0.0), _velocity(0.0), _elapsedS(0.0), _decay(decay)
  {}

  void spin(float velocity) {
    // Start the fidget spinner moving at the specified velocity (in pixels/second).
    // Over time the spinner will slow down based on its decay value.
    _velocity = velocity;
    _elapsedS = 0.0;  // Reset elapsed time to start the decay from the beginning.
  }

  float getPosition(float deltaS) {
    // Get the fidget spinner's current position after moving for the specified number
    // of milliseconds.  Returns a continuous value in the range 0...<10.
    _elapsedS += deltaS;
    // Compute current velocity based on exponential decay of initial
    // velocity over the elapsed time (this causes the spinner to
    // gradually slow down and mimics the effects of friction).
    float currentVelocity = _velocity*pow(_decay, _elapsedS);
    // Now move the position based on the current velocity.
    _position += currentVelocity*deltaS;
    // Finally make sure position is constrained within 0...<10 range.
    _position = fmod(_position, 10.0);
    if (_position < 0.0) {
      // Ensure position is never negative by wrapping back to the
      // same pixel position in a positive location.
      _position += 10.0;
    }
    return _position;
  }

private:
  float _position;
  float _velocity;
  float _elapsedS;
  float _decay;
};

#endif
