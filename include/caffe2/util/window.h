#ifndef UTIL_WINDOW_H
#define UTIL_WINDOW_H

#include <opencv2/opencv.hpp>

#include <map>

namespace caffe2 {

class WindowUtil {
  struct View {
    cv::Rect rect;
    std::string title;
    bool frameless;
  };

 public:
  void ResizeWindow(cv::Rect rect);
  void SizeWindow(cv::Size size);
  void PositionWindow(cv::Point position);
  void EnsureWindow(cv::Rect rect);

  void ResizeView(const std::string &name, cv::Rect rect);
  void SizeView(const std::string &name, cv::Size size);
  void OffsetView(const std::string &name, cv::Point offset);
  void AutosizeView(const std::string &name);
  void TitleView(const std::string &name, const std::string &title);

  void ShowImage(const std::string &name, const cv::Mat &image, bool flush);
  void ShowText(const std::string &name, const std::string &text,
                cv::Point position);
  void ShowFrame(const std::string &name, const std::string &title,
                 cv::Scalar foreground = {32, 224, 32},
                 cv::Scalar background = {32, 32, 32},
                 cv::Scalar text = {0, 0, 0});
  cv::Mat GetBuffer(const std::string &name, cv::Rect &rect);
  void ShowBuffer(const std::string &name, bool flush);

  void SetTitle(const std::string &title);
  void Show();

 protected:
  cv::Point position_;
  cv::Mat buffer_;
  std::string title_;
  std::map<std::string, View> views_;
};

void superWindow(const char *title, int width = 0, int height = 0);
void moveWindow(const char *name, int x, int y);
void resizeWindow(const char *name, int width, int height);
void autosizeWindow(const char *name);
void setWindowTitle(const char *name, const char *title);
void imshow(const char *name, const cv::Mat &mat, bool flush = true);
cv::Mat getBuffer(const char *name, cv::Rect &rect);
void showBuffer(const char *name, bool flush = true);

}  // namespace caffe2

#endif  // UTIL_WINDOW_H
