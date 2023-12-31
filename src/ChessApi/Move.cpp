#include "Move.h"
#include <cstddef>

Move *Move::_inst = NULL;

Move *Move::GetInst() {
  if (_inst == NULL) {
    _inst = new Move();
  }
  return _inst;
}
