#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"

// Invoked when cdc when line state changed e.g connected/disconnected
void tud_cdc_line_state_cb(uint8_t itf, bool dtr, bool rts)
{
  (void) itf;
  (void) rts;

  if (dtr)
  {
    // Terminal connected
  }
  else
  {
    // Terminal disconnected
  }
}

// Invoked when CDC interface received data from host
void tud_cdc_rx_cb(uint8_t itf)
{
  uint8_t buf[64];
  uint32_t count;

  // connected() check for DTR bit
  // Most but not all terminal client set this when making connection
  if (tud_cdc_connected())
  {
    if (tud_cdc_available()) // there are data available
    {
      count = tud_cdc_n_read(itf, buf, sizeof(buf));
      (void) count;

      tud_cdc_n_write(itf, buf, count);
      tud_cdc_n_write_flush(itf);
    }
  }
}