extern "C" int MyMain(unsigned long (*edk_print)(const char16_t* format, ...) __attribute__((ms_abi))){
    edk_print(u"Hello!!\nEnoshimaOS Ver1.0\n");
    return 0;   
}
