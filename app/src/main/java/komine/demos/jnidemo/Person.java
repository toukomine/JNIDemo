package komine.demos.jnidemo;

public class Person {
    //存放C++层对象的首地址地址
    private final long mNativeObject;

    public Person(String name,int age){
        mNativeObject = init(name,age);
    }

    private native long init(String name,int age);

    //实际开发中可能不会这么写,每个方法都传C/C++对象的首地址,这里只是演示
    private native String getName(long mNativeObject);
    private native int getAge(long mNativeObject);
    private native void setName(long mNativeObject,String name);
    private native void setAge(long mNativeObject,int age);

    public String getName(){
        return getName(mNativeObject);
    }

    public int getAge(){
        return getAge(mNativeObject);
    }

    public void setName(String name){
        setName(mNativeObject,name);
    }

    public void setAge(int age){
        setAge(mNativeObject,age);
    }
}
