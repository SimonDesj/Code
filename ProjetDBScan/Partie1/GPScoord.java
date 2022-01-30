public class GPScoord{ //constructor poor les coordonees GPS 
    private float latitude,longitude;
    public GPScoord(){ //default constructor

    }
    public GPScoord(float latitude,float longitude){ //constructor avec parametres
        this.latitude = latitude;
        this.longitude = longitude;
    }

    public float getLatitude() { //getter pour latitude
        return latitude;
    }
    public float getLongitude() { //getter pour longitude
        return longitude;
    }
    public void setLatitude(float latitude) { //setter pour latitude
        this.latitude = latitude;
    }
    public void setLongitude(float longitude) { //setter pour longitude
        this.longitude = longitude;
    }
    
}