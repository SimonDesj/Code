public class TripRecord{
    private String unnamed, pickup_DateTime;
    private GPScoord pickup_Location, dropoff_Location;
    private float trip_Distance;
    
    public TripRecord(){ //dfeault constructor

    }
    public TripRecord(String unnamed, String pickup_DateTime, 
                        GPScoord pickup_Location, GPScoord dropoff_Location, float trip_Distance){

        this.unnamed = unnamed;
        this.pickup_DateTime = pickup_DateTime;
        this.pickup_Location = pickup_Location;
        this.dropoff_Location = dropoff_Location;
        this.trip_Distance = trip_Distance;
    }
    public String getUnnamed(){ //getter pour unnamed
        return unnamed;
    }
    public GPScoord getPickupLocation(){ //getter pour pickup_location
        return pickup_Location;
    }
    public GPScoord getDropoffLocation(){ //getter pour dropoff_location
        return dropoff_Location;
    }
    public String getPickupTime(){ //getter pour pickup_DateTime
        return pickup_DateTime;
    }
    public float getTripDistance(){ //getter pour trip distance
        return trip_Distance;
    }
    
}