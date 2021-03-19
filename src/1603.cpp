class ParkingSystem {
public:
    //并未要求实现车离开这个函数
    //5分钟，时间击败：46.72%，空间击败：45.03%
    ParkingSystem(int big, int medium, int small):bigPark(big), 
                                                  medPark(medium),
                                                  smallPark(small) {
    //题目指出，big/medium/small不小于0

    }
    
    bool addCar(int carType) {
        //题目指出，cartype只会是1\2\3
        if(carType == 1 && bigPark > 0){
            bigPark--;
            return true;
        }
        else if(carType == 2 && medPark > 0){
            medPark --;
            return true;
        }
        else if(carType == 3 && smallPark > 0){
            smallPark --;
            return true;
        }
        else{
            return false;
        }
    }
private:
    unsigned int bigPark;    //大车停车位
    unsigned int medPark;    //中停车位
    unsigned int smallPark;  //小停车位
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
