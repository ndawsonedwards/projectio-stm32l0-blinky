# PlatformIO-stm32l0-blinky
Simple project to test out PlatformIO with ST Nucleo-L031k6


Uses Platform IO IDE extension of VSCode. 
See https://platformio.org/ for more details

## First impressions
 - Project setup was very easy and streamline. All necessary build tools are automatically downloaded 
 - HAL libraries are automatically downloaded for target and integrated into build 

 - Hiccups getting things going: 
   - No code generation to initialize peripherals. I basically needed to create a seperate project with STM32CubeMX, copy peripheral initializations. I aint got time to hand craft peripheral initializations. 
   - No code generation for SysTic increment. So HAL calls just go stuck on any HAL_Delay calls or RCC PLL initializations. 
   - RCC was configured to sourcing HSI as it was hung up on PLL lock before I realied it was due to SysTick issue aove. 
  - First impressions of just getting working peripherals running on target is that I'd rather just use "STM32 VS Code Extension" extension, built by STM32. Getting a GPIO toggle and Uart TX working with ST designed extension took way less time since peripheral code generation is built it. 

 - Final Thoughts
   - Perhaps PlatformIO would be a better solution for othe boards/platforms, such as RP2040/ESP32, but it falls short against integrated stm32 support.
   - No more activity is expected on this repo
