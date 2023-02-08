#include "weight_cell.h"

HX711 scale;

void setup_weight_cell(){
    Serial.println("Weight cell start");
    rtc_clk_cpu_freq_set(RTC_CPU_FREQ_80M);
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(CALIBRATION_FACTOR);
    scale.tare();
    Serial.println("Weight cell setup complete");
}

void set_calibrate_scale(){
    if (scale.is_ready()){
        
    }
    else{
        Serial.println("HX711 not found.");
    }
    delay(500);
}


void get_calibration(){
    if (scale.is_ready()) {
        scale.set_scale();    
        Serial.println("Tare... remove any weights from the scale.");
        delay(5000);
        scale.tare();
        Serial.println("Tare done...");
        Serial.print("Place a known weight on the scale...");
        delay(5000);
        long reading = scale.get_units(10);
        Serial.print("Result: ");
        Serial.println(reading);
    } 
    else {
        Serial.println("HX711 not found.");
    }
    delay(1000);
}
float get_weight()
{
    return scale.get_units(10);
}
