# 自动驾驶的决策与规划模块

## 目前我想做的工作

- 一个良好的可视化模块(正在做的工作，调研了 OpenGL 以及 WebGL, 最后还是选择 OpenGL 来开发。进度太慢，选择autoware2作为我们的开发平台，可视化选择（rviz, OPENGL开发亦可同步进行）
- 一个良好的地图
- 坐标系，禁止 frenet 坐标系
- 地图，禁止各种参数化曲线地图，
- 一个良好的结构化环境的规划器
  - 路径规划器
  - 速度规划器, 禁止 ST 图
  - 禁止依赖某种参数化参考线（frenet）
- 一个良好的非结构化环境的规划器
- 一个良好的决策器,状态机设计

## 开发规范

- 代码格式要求： .clang_format
- 如无必要，勿增实体;
- 最好避免重复造轮子，利用好开源代码
- 出现 corner case 时写上 utest
- 最好测试重要函数的性能
- 最好利用上日志系统，方便检查。
- 在一个版本比较稳定的时候，最好打上版本标签(Tag)
- 最好不要直接在系统里面安装环境，而使用 git submodule, 然后利用 Cmake 链接上。对于需要的依赖，及时补充在 Depends 目录下
- 关于代码文档，及时补充上参考资料。

## Depends

- openCV
- openGL
- Eigen
- Googletest
- Google Benchmark
- box2d
- lanelet2
- GLFW
- Open DDS
- Ubuntu 20.04
- Cmake 3.5.1(at least)
- autoware2(版本号等待测试完毕再确认)

## 开发文档

### OpenGL

- [LearnOpenGL-CN github 链接](https://github.com/LearnOpenGL-CN/LearnOpenGL-CN)
- [LearnOpenGL-CN docs 链接](https://learnopengl-cn.github.io/)

#### glfw

用于显示窗口

### WebGL
