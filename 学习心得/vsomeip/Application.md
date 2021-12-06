# Application

### app->init

1. 读取环境变量中的VSOMEIP_ENV_APPLICATION_NAME 应用名字
2. 加载配置模块get_configuration(应用名字), 通过configuration_impl中的load方法，读取环境变量中的VSOMEIP_ENV_CONFIGURATION
3. 初始化应用，从配置对象configuration_中获取app的clientid等信息
4. 初始化 routing manager [Host]

### app->start

1. 创建四个线程
2. 一个main_dispatch 主调度线程，用于执行放在队列中的handle
3. stop_thread线程用来join或者detach其他的线程
4. 两个io线程，利用了boost的io_service类对象