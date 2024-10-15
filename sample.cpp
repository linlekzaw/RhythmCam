#include <opencv2/opencv.hpp>
#include <openpose/headers.hpp>

// Function to extract keypoints from video
std::vector<std::vector<float>> extractKeypointsFromVideo(const std::string& videoPath) {
    // Initialize OpenPose
    op::Wrapper opWrapper(op::ThreadManagerMode::Asynchronous);
    opWrapper.start();

    std::vector<std::vector<float>> keypointsList;
    cv::VideoCapture cap(videoPath);

    while (true) {
        cv::Mat frame;
        cap >> frame;
        if (frame.empty()) break;

        // Process frame with OpenPose
        auto datumProcessed = opWrapper.emplaceAndPop(frame);
        if (datumProcessed != nullptr) {
            const auto& keypoints = datumProcessed->at(0)->poseKeypoints;
            keypointsList.push_back(keypoints);
        }
    }
    return keypointsList;
}

// Function to compare keypoints
float compareKeypoints(const std::vector<float>& refKeypoints, const std::vector<float>& realTimeKeypoints) {
    float distance = 0.0;
    // Compute Euclidean distance between corresponding keypoints
    for (int i = 0; i < refKeypoints.size(); i++) {
        float diff = refKeypoints[i] - realTimeKeypoints[i];
        distance += diff * diff;
    }
    return sqrt(distance);
}

int main() {
    // Load video keypoints
    auto referenceKeypoints = extractKeypointsFromVideo("dance_reference.mp4");

    // Initialize real-time capture
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) return -1;

    while (true) {
        cv::Mat frame;
        cap >> frame;

        // Extract keypoints from real-time camera feed
        auto realTimeKeypoints = extractKeypointsFromCamera(frame);

        // Compare poses
        float distance = compareKeypoints(referenceKeypoints, realTimeKeypoints);

        // Display feedback
        if (distance < threshold) {
            std::cout << "Good job! Keep it up!" << std::endl;
        } else {
            std::cout << "Try adjusting your pose." << std::endl;
        }

        // Display frame
        cv::imshow("Dance Comparison", frame);
        if (cv::waitKey(1) == 'q') break;
    }
    return 0;
}
