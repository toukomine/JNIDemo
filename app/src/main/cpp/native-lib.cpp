#include <jni.h>
#include <string>
#include "Person.h"


extern "C"
JNIEXPORT jstring JNICALL
Java_komine_demos_jnidemo_MainActivity_getName(JNIEnv *env, jobject thiz) {
    //3.获取Java层的jclass
    jclass mainActivityClass = env->FindClass("komine/demos/jnidemo/MainActivity");

    //2.获取Java层字段的定义
    jfieldID nameFieldId = env->GetFieldID(mainActivityClass,"mName", "Ljava/lang/String;");

    //1.获取字段的值
    jobject name = env->GetObjectField(thiz,nameFieldId);


    return static_cast<jstring>(name);
}

extern "C"
JNIEXPORT void JNICALL
Java_komine_demos_jnidemo_MainActivity_alert(JNIEnv *env, jobject thiz) {

    //3.获取jclass对象
    jclass mainActivityClass = env->FindClass("komine/demos/jnidemo/MainActivity");

    //2.获取一个方法的id
    jmethodID alertMessageMethodId = env->GetMethodID(mainActivityClass,"alertMessage", "(Ljava/lang/String;)V");

    jstring msg = env->NewStringUTF("来自C/C++的方法调用!");

    //1 调用一个无返回值的方法
    env->CallVoidMethod(thiz,alertMessageMethodId,msg);
}

Person *person = NULL;

extern "C"
JNIEXPORT jlong JNICALL
Java_komine_demos_jnidemo_Person_init(JNIEnv *env, jobject thiz, jstring name, jint age) {

    string nameStr = env->GetStringUTFChars(name,NULL);
    person = new Person(nameStr,age);

    return reinterpret_cast<jlong>(person);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_komine_demos_jnidemo_Person_getName(JNIEnv *env, jobject thiz, jlong m_native_object) {
    Person *p = reinterpret_cast<Person *>(m_native_object);

    return env->NewStringUTF(p->getName().c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_komine_demos_jnidemo_Person_getAge(JNIEnv *env, jobject thiz, jlong m_native_object) {
    Person *p = reinterpret_cast<Person *>(m_native_object);

    return p->getAge();
}

extern "C"
JNIEXPORT void JNICALL
Java_komine_demos_jnidemo_Person_setName(JNIEnv *env, jobject thiz, jlong m_native_object,
                                         jstring name) {
    Person *p = reinterpret_cast<Person *>(m_native_object);
    p->setName(env->GetStringUTFChars(name,NULL));
}

extern "C"
JNIEXPORT void JNICALL
Java_komine_demos_jnidemo_Person_setAge(JNIEnv *env, jobject thiz, jlong m_native_object,
                                        jint age) {
   Person *p = reinterpret_cast<Person *>(m_native_object);
   p->setAge(age);
}


extern "C"
JNIEXPORT jobject JNICALL
Java_komine_demos_jnidemo_MainActivity_createPoint(JNIEnv *env, jobject thiz, jint x, jint y) {
    //3.获取Java对象的class
    jclass pointClass = env->FindClass("android/graphics/Point");

    //2.获取构造函数方法签名
    jmethodID initMethodId = env->GetMethodID(pointClass,"<init>", "(II)V");

    //1.调用JNIEnv的NewObject()方法创建一个Java对象
    jobject pointObj = env->NewObject(pointClass,initMethodId,x,y);

    jobject  p = env->AllocObject(pointClass);

    //4.返回创建好的对象
    return pointObj;
}