DanceSync is a real-time dance comparison tool using OpenPose to capture and compare your movements with a reference dance video. Designed for dancers and enthusiasts, this C++ project helps users learn, practice, and improve their dance by offering real-time feedback on how closely their poses match the choreography.

Overview

DanceSync leverages real-time camera input and machine learning techniques for human pose detection using OpenPose. It allows users to compare their dance moves with a reference video by tracking key body points and offering detailed feedback to help them improve. The application provides visual cues that indicate how closely the user's dance matches the reference video.

Features

Real-Time Pose Detection: Detects body pose points in real-time using OpenPose via a webcam.

Pose Accuracy Feedback: Provides visual cues indicating how accurately the user's movements match the reference video.

Customizable Video Input: Allows users to load their own reference dance videos.

Frame-by-Frame Syncing: Compares each frame of the user's performance with the reference video.

Cross-Platform: Works on multiple operating systems like Windows, Linux, and macOS (with OpenPose configured for the platform).


Technology Used

C++: Core programming language for high-performance real-time processing.

OpenPose: For pose estimation and human keypoint detection.

OpenCV: For video capture, frame processing, and image manipulation.

CMake: For building and compiling the project.

Installation
Prerequisites

CMake: Ensure CMake is installed on your machine.

OpenPose: Follow the OpenPose installation guide to install OpenPose.

OpenCV: Make sure OpenCV is installed and configured on your system.

Usage

Load Reference Video: Load your preferred dance video via the interface or specify it in the code.

Start Camera Input: Begin tracking and comparing dance moves in real-time.

Receive Feedback: Watch how your moves sync with the reference video through visual feedback.

Technology Stack


C++: Core functionality and real-time processing.

OpenPose: Used for pose estimation and human keypoint detection.

OpenCV: For handling video capture, playback, and image processing.

CMake: Build tool used to manage project compilation.

Acknowledgments


This project would not have been possible without the following:

OpenPose: For making human pose estimation easier to implement in real-time.

OpenCV: For the robust image and video processing tools.

The C++ community: For its contributions to performance-oriented real-time applications.
