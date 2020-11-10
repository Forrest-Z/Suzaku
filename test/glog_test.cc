#include <glog/logging.h>

int main(int argc, char *argv[])
{
    google::InitGoogleLogging(argv[0]);
    google::SetLogDestination(
            google::INFO, "./");  // 把日志同时记录文件，最低级别为INFO

    // 通过GFLAGS来设置参数，更多选项可以在logging.cc里面查询
    // 日志等级分为INFO, WARNING, ERROR, FATAL,如果是FATAL级别这直接运行报错
    FLAGS_stderrthreshold = google::WARNING;
    FLAGS_colorlogtostderr = true;

    LOG(WARNING) << "Hello GLOG";
    // 条件输出
    LOG_IF(INFO, 20 > 10) << "20 > 10";
    // 频率输出，本质上是通过google::COUNTER这个计数机实现的
    for (int i = 0; i < 10; i++)
    {
        LOG_EVERY_N(ERROR, 3) << "每隔3次输出一次 " << i;
        LOG_FIRST_N(ERROR, 2) << "前两次输出 " << i;
        LOG_IF_EVERY_N(WARNING, 1 < 2, 2) << "条件输出+频率" << google::COUNTER;
    }
    google::ShutdownGoogleLogging();
}