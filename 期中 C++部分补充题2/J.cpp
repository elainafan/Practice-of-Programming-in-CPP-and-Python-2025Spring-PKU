template<class T,class Pred>
T Myaccumulate(T* x,int num,Pred f){
  T temp=f(*x);
  for(T* it=x+1;it<x+num;it++){
    temp+=f(*it);
  }
  return temp;
}
template<class T>
class MyAccumulate{
  T temp;
public:
  MyAccumulate() { }
  template<class Pred>
  T operator()(T* x,int num,Pred f){
    temp=f(*x);
    for(T* it=x+1;it<x+num;it++){
    temp+=f(*it);
    }
    return temp;
  }
};