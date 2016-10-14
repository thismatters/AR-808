#define F_CPU    16000000
#define N_CHANNELS      5
#define N_BUTTON_ROWS   4
#define N_LED_ROWS      4
#define N_FUNC_ROWS     4
// variables
int channels[N_CHANNELS] = {A2, A3, 2, 3, 4};
int button_rows[N_BUTTON_ROWS] = {8, 5, 6, 7};
int led_row_pins[N_LED_ROWS] = {9, 10, 11, 12};
// int func_rows[N_FUNC_ROWS] = {}; // these are on the MCP
bool desired_led_state[N_CHANNELS][N_LED_ROWS] = {0};
// see ergodox source for dealing with the MCP!!
    // channel0
    // channel1
    // channel2
    // channel3
    // channel4
    // channels = [channel0, channel1, channel2, channel3, channel4];
    // button_row0
    // button_row1
    // button_row2
    // button_row3
    // function_row0
    // function_row1
    // function_row2
    // function_row3


// initialize
// From LightController.ino, for reference:
// int feedback_pins[N] = {5, 6, 7, 8, 12, 11, 10, 9};
// int output_pins[N] = {3, 2, A0, A1, A5, A4, A3, A2};
// void setup() {
//     for (int i=0; i<N; i++) {
//         pinMode(feedback_pins[i], INPUT);
//         pinMode(output_pins[i], OUTPUT);
//         lights_on[i] = false;
//         lights_in[i] = false;
//     }
// }

// Set up timer

void set_pin_off(int pin) {/* set pin to the hi-impedence mode.*/}
void set_pin_low(int pin) {/* set pin to the low logic level.*/}
void set_pin_high(int pin) {/* set pin to the high logic level.*/}
uint8_t read_selector_state() {/* read the input pins of the mcp23017*/} 
uint8_t read_button_state() {/* read the input pins on the atmega*/
    //input_state += <read_bit> << func_row
}
void  set_led_state(uint8_t state) {/* set the led output pins */}

void enact_selector_state(int chan, uint8_t state) {
    // decode the selector state and do the appropriate things
    switch (chan) {
        case 0:
            // voice selector
            if (selected_voice != state) {
                set_selected_voice(state);
            }
            break;
        case 1:
            // mode selector
            if (selected_mode != state) {
                set_selected_mode(state);
            }
            break;
        case 2:
            // autofill selector
            if (selected_autofill != state) {
                set_selected_autofill(state);
            }
            break;
        case 3:
            // A-B selector and I-F A-B selector
            uint8_t ab_state = state & 0x03;
            uint8_t if_state = (state & 0x0C) >> 2; 
            if (selected_ab != ab_state) {
                set_selected_ab(ab_state);
            }
            if (selected_if != if_state) {
                set_selected_if(if_state);
            }
            break;
        case 4:
            // prescale selector
            if (selected_prescale != state) {
                set_selected_prescale(state);
            }
            break;
        default:
            return;
    }
}

int main(void) {  
    // scan the input channels
    int row_pin;
    for(int chan=0; chan<N_CHANNELS; chan++) {
        // activate channel
        chan_pin = channels[chan];
        set_pin_high(chan_pin);
        
        // turn on appropriate LEDs on this channel
        for (int led_row=0; led_row<N_LED_ROWS; led_row++) {
            row_pin = led_row_pins[led_row];
            if (desired_led_state[chan][led_row]) {
                set_pin_high(row_pin);
            } else {
                set_pin_low(row_pin);
            }
        }
        
        // read states of inputs on this channel
        selector_state = read_selector_state();
        // decode input_state
        enact_selector_state(chan, selector_state);
        button_state = read_button_state();

        // turn off LEDs on this channel
        for (int led_row=0; led_row<N_LED_ROWS; led_row++) {
            row_pin = led_row_pins[led_row];
            set_pin_low(row_pin);
        }

        // deactivate channels[chan]
        set_pin_off(chan_pin);
    }
    // every so often change which output channel is active
    // correlate the input codes to functions per each output
    // check tempo and update timer appropriately

    // do functions according to how the knobs are set
    
    // if playing
        // grab next beat bytes from memory (eeprom or program space if already loaded)


    // if next beat is unset
        // load next beat from memory
        // push next beat to MCP
        // set next beat flag
      
}