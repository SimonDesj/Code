import java.io.File;
import java.util.ArrayList;

public class Cluster{
    TripRecord records;
    private boolean visited = false;
    private int Cid = 0;
    public Cluster(){

    }
    public Cluster(TripRecord records){
        this.records = records;
    }
    public TripRecord getTripRecord(){
        return records;
    }
    public double[] getVector() {
        return null;
    }

    public void setCid(int i) {
        Cid = i;
    }

    public int getCid() {
        return Cid;
    }

    public void setVisited(boolean b) {
        visited = b;
    }

    public boolean isVisited() {
        return visited;
    }

    
    
}