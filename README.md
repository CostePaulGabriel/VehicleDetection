# VehicleDetection

Crossplatform 2D vehicle detection software written in cpp, using Qt6 and OpenCV.  
Designed to work on a Raspberry Pi4 model B 8GB with a RPi Camera Module 3.  

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Installation

1. Clone the repository:
```bash
git clone https://github.com/CostePaulGabriel/VehicleDetection.git -j8
```

2. Install CMake 3.22.1 or higher.

3. Install Qt6 version or higher. The version that I used is Qt Creator 8.0.0.  

4. During cmake configuration all the thirdparty dependencies such as OpenCV 4.6.0, should be downloaded automatically in the 'Thirdparty' directory.  

5. Build OpenCV libraries:  

- In the Thirdparty directory open a Command Prompt and type:
```bash
cd opencv  
mkdir build && cd build  
cmake-gui ..  
```

- **From the CMake GUI**:
  1. Select the preferred compiler.
  2. Click on the "Configure" button.
  3. Click on the "Generate" button.
  4. Click on the "Open" button to open the generated project files.

If MSVC 2022 was used, follow these steps:

1. **Set 'ALL_BUILD' as Startup Project**:
   - From the Solution Explorer, right-click on 'ALL_BUILD' target.
   - Select "Set as Startup Project".

2. **Build in Release and Debug Configurations**:
   - Build the solution in both Release and Debug configurations.

3. **Switch to 'INSTALL' Target**:
   - From the Solution Explorer, switch to the 'INSTALL' target.

4. **Build Again in Both Configurations**:
   - Build the solution again in both Release and Debug configurations.

## Usage

 -

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
