def vel(jarakTempuh,waktuTempuh):
    return jarakTempuh/waktuTempuh
    
def avgvel(jarakTempuh1,waktuTempuh1,jarakTempuh2,waktuTempuh2):
    return (vel(jarakTempuh1,waktuTempuh1)+vel(jarakTempuh2,waktuTempuh2))/2

print(avgvel(100,1,100,2.5))