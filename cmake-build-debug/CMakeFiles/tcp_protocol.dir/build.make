# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\git\tcp-protocol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\git\tcp-protocol\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tcp_protocol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tcp_protocol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tcp_protocol.dir/flags.make

CMakeFiles/tcp_protocol.dir/main.cpp.obj: CMakeFiles/tcp_protocol.dir/flags.make
CMakeFiles/tcp_protocol.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tcp_protocol.dir/main.cpp.obj"
	D:\programes\CLion\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tcp_protocol.dir\main.cpp.obj -c D:\git\tcp-protocol\main.cpp

CMakeFiles/tcp_protocol.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_protocol.dir/main.cpp.i"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\tcp-protocol\main.cpp > CMakeFiles\tcp_protocol.dir\main.cpp.i

CMakeFiles/tcp_protocol.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_protocol.dir/main.cpp.s"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\tcp-protocol\main.cpp -o CMakeFiles\tcp_protocol.dir\main.cpp.s

CMakeFiles/tcp_protocol.dir/Client/Client.cpp.obj: CMakeFiles/tcp_protocol.dir/flags.make
CMakeFiles/tcp_protocol.dir/Client/Client.cpp.obj: ../Client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tcp_protocol.dir/Client/Client.cpp.obj"
	D:\programes\CLion\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tcp_protocol.dir\Client\Client.cpp.obj -c D:\git\tcp-protocol\Client\Client.cpp

CMakeFiles/tcp_protocol.dir/Client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_protocol.dir/Client/Client.cpp.i"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\tcp-protocol\Client\Client.cpp > CMakeFiles\tcp_protocol.dir\Client\Client.cpp.i

CMakeFiles/tcp_protocol.dir/Client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_protocol.dir/Client/Client.cpp.s"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\tcp-protocol\Client\Client.cpp -o CMakeFiles\tcp_protocol.dir\Client\Client.cpp.s

CMakeFiles/tcp_protocol.dir/Server/Server.cpp.obj: CMakeFiles/tcp_protocol.dir/flags.make
CMakeFiles/tcp_protocol.dir/Server/Server.cpp.obj: ../Server/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tcp_protocol.dir/Server/Server.cpp.obj"
	D:\programes\CLion\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tcp_protocol.dir\Server\Server.cpp.obj -c D:\git\tcp-protocol\Server\Server.cpp

CMakeFiles/tcp_protocol.dir/Server/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_protocol.dir/Server/Server.cpp.i"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\tcp-protocol\Server\Server.cpp > CMakeFiles\tcp_protocol.dir\Server\Server.cpp.i

CMakeFiles/tcp_protocol.dir/Server/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_protocol.dir/Server/Server.cpp.s"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\tcp-protocol\Server\Server.cpp -o CMakeFiles\tcp_protocol.dir\Server\Server.cpp.s

CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.obj: CMakeFiles/tcp_protocol.dir/flags.make
CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.obj: ../File\ Handler/FileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.obj"
	D:\programes\CLion\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tcp_protocol.dir\File_Handler\FileReader.cpp.obj -c "D:\git\tcp-protocol\File Handler\FileReader.cpp"

CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.i"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\git\tcp-protocol\File Handler\FileReader.cpp" > CMakeFiles\tcp_protocol.dir\File_Handler\FileReader.cpp.i

CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.s"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\git\tcp-protocol\File Handler\FileReader.cpp" -o CMakeFiles\tcp_protocol.dir\File_Handler\FileReader.cpp.s

CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.obj: CMakeFiles/tcp_protocol.dir/flags.make
CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.obj: ../File\ Handler/FileWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.obj"
	D:\programes\CLion\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tcp_protocol.dir\File_Handler\FileWriter.cpp.obj -c "D:\git\tcp-protocol\File Handler\FileWriter.cpp"

CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.i"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\git\tcp-protocol\File Handler\FileWriter.cpp" > CMakeFiles\tcp_protocol.dir\File_Handler\FileWriter.cpp.i

CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.s"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\git\tcp-protocol\File Handler\FileWriter.cpp" -o CMakeFiles\tcp_protocol.dir\File_Handler\FileWriter.cpp.s

CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.obj: CMakeFiles/tcp_protocol.dir/flags.make
CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.obj: ../Sender/Sender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.obj"
	D:\programes\CLion\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tcp_protocol.dir\Sender\Sender.cpp.obj -c D:\git\tcp-protocol\Sender\Sender.cpp

CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.i"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\tcp-protocol\Sender\Sender.cpp > CMakeFiles\tcp_protocol.dir\Sender\Sender.cpp.i

CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.s"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\tcp-protocol\Sender\Sender.cpp -o CMakeFiles\tcp_protocol.dir\Sender\Sender.cpp.s

CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.obj: CMakeFiles/tcp_protocol.dir/flags.make
CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.obj: ../Receiver/Receiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.obj"
	D:\programes\CLion\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tcp_protocol.dir\Receiver\Receiver.cpp.obj -c D:\git\tcp-protocol\Receiver\Receiver.cpp

CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.i"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\tcp-protocol\Receiver\Receiver.cpp > CMakeFiles\tcp_protocol.dir\Receiver\Receiver.cpp.i

CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.s"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\tcp-protocol\Receiver\Receiver.cpp -o CMakeFiles\tcp_protocol.dir\Receiver\Receiver.cpp.s

CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.obj: CMakeFiles/tcp_protocol.dir/flags.make
CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.obj: ../Packet/PacketHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.obj"
	D:\programes\CLion\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tcp_protocol.dir\Packet\PacketHandler.cpp.obj -c D:\git\tcp-protocol\Packet\PacketHandler.cpp

CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.i"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\tcp-protocol\Packet\PacketHandler.cpp > CMakeFiles\tcp_protocol.dir\Packet\PacketHandler.cpp.i

CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.s"
	D:\programes\CLion\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\tcp-protocol\Packet\PacketHandler.cpp -o CMakeFiles\tcp_protocol.dir\Packet\PacketHandler.cpp.s

# Object files for target tcp_protocol
tcp_protocol_OBJECTS = \
"CMakeFiles/tcp_protocol.dir/main.cpp.obj" \
"CMakeFiles/tcp_protocol.dir/Client/Client.cpp.obj" \
"CMakeFiles/tcp_protocol.dir/Server/Server.cpp.obj" \
"CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.obj" \
"CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.obj" \
"CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.obj" \
"CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.obj" \
"CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.obj"

# External object files for target tcp_protocol
tcp_protocol_EXTERNAL_OBJECTS =

tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/main.cpp.obj
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/Client/Client.cpp.obj
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/Server/Server.cpp.obj
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/File_Handler/FileReader.cpp.obj
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/File_Handler/FileWriter.cpp.obj
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/Sender/Sender.cpp.obj
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/Receiver/Receiver.cpp.obj
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/Packet/PacketHandler.cpp.obj
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/build.make
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/linklibs.rsp
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/objects1.rsp
tcp_protocol.exe: CMakeFiles/tcp_protocol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\git\tcp-protocol\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable tcp_protocol.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tcp_protocol.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tcp_protocol.dir/build: tcp_protocol.exe

.PHONY : CMakeFiles/tcp_protocol.dir/build

CMakeFiles/tcp_protocol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tcp_protocol.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tcp_protocol.dir/clean

CMakeFiles/tcp_protocol.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\git\tcp-protocol D:\git\tcp-protocol D:\git\tcp-protocol\cmake-build-debug D:\git\tcp-protocol\cmake-build-debug D:\git\tcp-protocol\cmake-build-debug\CMakeFiles\tcp_protocol.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tcp_protocol.dir/depend

