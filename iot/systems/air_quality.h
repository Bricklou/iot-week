#ifndef AIR_QUALITY_SYSTEM_H
#define AIR_QUALITY_SYSTEM_H

#include "../sensors/air_quality.h"
#include "alert.h"


void check_air_quality() {
  if (air_quality_polluted())
  {
    // Run the alert process
    alert_t alert{
        .message = "Piece polluee. Aerez.",
        .type = alert_type_air_quality,
    };
    emit_alert(alert);
  }
}

#endif