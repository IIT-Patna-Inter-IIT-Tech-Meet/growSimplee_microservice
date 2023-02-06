# ESP32 code for GrowSimplee [PS: Part 1]
# 

## Running instructions
- Open this project in Arduino IDE
- Install the ESP32 board in Arduino IDE
- Select the board as ESP32 Dev Module
- Select the port
- Complile
- Upload and Click the `boot` button while uploading

## Code Structure
- `grow_simplee.ino` is the main file which contains the `setup()` and `loop()` functions
- The other folders containes the code for the different modules
- For adding a new module, 
    - Create a new folder with the name of the module
    - Create a new `.h` and `.cpp` file with the same name
    - include the `.h` file in `grow_simplee.ino` with relative path
    - include the `.h` file in corresponding `.cpp` file with relative path
- User some text editor to edit the code, like `VS Code` or `vim`, you can't see the files in arduino IDE


## Modules
- `wifi` - Contains the code for connecting to the wifi
- `ultrasonic` - Contains the code for ultrasonic sensor
- `weight` - Contains the code for weight cell
- `display` - Contains the code for `64x128` OLED display

## Sub-Doc
- [ESP_PIN_MAP](./PIN_MAP.md)
- [Display_Module](./src/display/mini_doc.md)