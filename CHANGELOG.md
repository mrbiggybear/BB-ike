
# Change Log
All notable changes to this project will be documented in this file.
<!--  
The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).
  -->
## [Unreleased] - TBA
 
- Develope Motion and Speed functionality to prepare for future feature additions.
- Develope logging feature.
- Design logging storage.
- Develope remote communication functions.
- Intergrate Motion and Speed features.
- Refine application behavior loop.
- Refactor code.
 
### Added
   
- Create namespaces for...
  - Lights
  - Network
  - IO 
  - Info
- Created Lights.h
  - Created Light class (state)
  - Create functions to operate on light objcts (logic)
- Created Networks.h
  - Placed all network configurations and function in Network namespace.
- Created Device.h
  - Create Info and IO to organize all device information and i/o configurations.
  
### Changed

Files were created and function were placed into various namespaces and files to help with functionality and readability.
 
<!-- ### Deprecated  -->
  
### Removed 

- ~~README.md~~

### Fixed
 
- Refactored Code.
