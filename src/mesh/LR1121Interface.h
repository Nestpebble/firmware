#pragma once

#include "LR11x0Interface.h"

/**
 * Our adapter for LR1121 wideband radios
 */
class LR1121Interface : public LR11x0Interface<LR1121>
{
  public:
    LR1121Interface(LockingArduinoHal *hal, RADIOLIB_PIN_TYPE cs, RADIOLIB_PIN_TYPE irq, RADIOLIB_PIN_TYPE rst,
                    RADIOLIB_PIN_TYPE busy);
    bool wideLora() override;
};