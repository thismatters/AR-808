// CPU STUFF

#define N_CHANNELS      5
#define N_BUTTON_ROWS   4
#define N_FUNC_ROWS     4
// variables
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
    // Set up timer


// main run loop
int main(void) {  
    // scan the input channels
    for(int chan=0; chan<N_CHANNELS; chan++) {
        // activate channels[chan]
        // turn on appropriate LEDs on this channel
        // read states of inputs on this channel
        input_state = 0;
        for (int func_row=0; func_row<N_FUNC_ROWS; func_row++) {
            input_state += <read_bit> << func_row
        }
        // decode input_state
        // turn off LEDs on this channel
        // deactivate channels[chan]
    }
    // every so often change which output channel is active
    // correlate the input codes to functions per each output
    // check tempo and update timer appropriately

    // do functions according to how the knobs are set
    
    // if next beat is unset
        // load next beat from memory
        // push next beat to MCP
        // set next beat flag
      
}