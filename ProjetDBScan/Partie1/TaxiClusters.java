
//https://www.programmerall.com/article/4404823021/ 
//J'ai pris l'algorithme de ce site ici
//https://www.javatpoint.com/how-to-read-csv-file-in-java inspirer de ce document pour comment lire d'un file csv 




import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Vector;
import java.util.Iterator;

class TaxiClusters{

    
    double Eps=3; //area radius
     int MinPts=4; //density
     
     //Because the distance from oneself to oneself is 0, so oneself is also one's own neighbor
    public Vector<Cluster> getNeighbors(Cluster p,ArrayList<Cluster> objects){ //avec l'utilisation des vectors on implemente une fonction pour chercher des voisins du cluster
        Vector<Cluster> neighbors=new Vector<Cluster>();
        Iterator<Cluster> iter=objects.iterator();
        while(iter.hasNext()){
            Cluster q=iter.next();
           // mute for now double[] arr1=p.getVector();
            GPScoord arr1 = p.getTripRecord().getPickupLocation();
            GPScoord arr2 = p.getTripRecord().getPickupLocation();
            //double[] arr2=q.getVector();
            //int len=arr1.length;
             
             if(calculateDistance(start, end, distance))<=Eps){ //Use edit distance
 // if(Global.calEuraDist(arr1, arr2, len)<=Eps){ //Use Euclidean distance  
 // if(Global.calCityBlockDist(arr1, arr2, len)<=Eps){ //Use block distance
 // if(Global.calSinDist(arr1, arr2, len)<=Eps){ //Use the sine of the vector angle
                neighbors.add(q);
            }
        }
        return neighbors;
    }
     
    public int dbscan(ArrayList<Cluster> objects){
        int clusterID=0;
        boolean AllVisited=false;
        while(!AllVisited){
            Iterator<Cluster> iter=objects.iterator();
            while(iter.hasNext()){
                Cluster p=iter.next();
                if(p.isVisited())
                    continue;
                AllVisited=false;
                 p.setVisited(true); //After set to visited, it has been determined whether it is a core point or a boundary point
                Vector<Cluster> neighbors=getNeighbors(p,objects);
                if(neighbors.size()<MinPts){
                    if(p.getCid()<=0)
                         p.setCid(-1); //cid is initially 0, which means unclassified; set to a positive number after classification; set to -1 to indicate noise.
                }else{
                    if(p.getCid()<=0){
                        clusterID++;
                        expandCluster(p,neighbors,clusterID,objects);
                    }else{
                        int iid=p.getCid();
                        expandCluster(p,neighbors,iid,objects);
                    }
                }
                AllVisited=true;
            }
        }
        return clusterID;
    }
 
    private void expandCluster(Cluster p, Vector<Cluster> neighbors,
            int clusterID,ArrayList<Cluster> objects) {
        p.setCid(clusterID);
        Iterator<Cluster> iter=neighbors.iterator();
        while(iter.hasNext()){
            Cluster q=iter.next();
            if(!q.isVisited()){
                q.setVisited(true);
                Vector<Cluster> qneighbors=getNeighbors(q,objects);
                if(qneighbors.size()>=MinPts){
                    Iterator<Cluster> it=qneighbors.iterator();
                    while(it.hasNext()){
                        Cluster no=it.next();
                        if(no.getCid()<=0)
                            no.setCid(clusterID);
                    }
                }
            }
             if(q.getCid()<=0){ //q is not a member of any cluster
                q.setCid(clusterID);
            }
        }
    }

    public double calculateDistance(GPScoord start, GPScoord end, int distance){
        double result = Math.sqrt(
            ((end.getLatitude() - start.getLatitude())*(end.getLatitude() - start.getLatitude()))
                + ((end.getLongitude() - start.getLongitude())*(end.getLongitude() - start.getLatitude()))
                ); //calculate point 
        return result;
    }
    
    public static void main(String[] args){
        int count = 0;
        ArrayList<Cluster> database = new ArrayList<Cluster>(); //je cree un array list de type TripRecord pour que je puisse cree un repertoire pour tout les trips de taxi pour que le programme puisse l'utiliser comme par exemple dans l'algorithme
        String line = "";
        try{
            BufferedReader buffRead = new BufferedReader(new FileReader("C:\\School\\CSI2520\\Projet\\Partie1\\yellow_tripdata_2009-01-15_1hour_clean.csv"));
            while((line = buffRead.readLine()) != null){
                if(count !=0 ){ //je mais un count restriction car la premiere ligne du fichier nous donne les noms et non les donnees
                    String[] data = line.split(","); //je prends ton l'information de la ligne et je le split pour le mettre dans un String array
                    
                    float s_long = Float.parseFloat(data[8]); //je parse les donners pour les coordonees et pour la distance du trajet
                    float s_lat = Float.parseFloat(data[9]); // ^^
                    GPScoord pickup_loc = new GPScoord(s_long,s_lat);
                    float e_long = Float.parseFloat(data[12]);
                    float e_lat = Float.parseFloat(data[13]);
                    float tripDist = Float.parseFloat(data[7]);
                    GPScoord end_loc = new GPScoord(e_long,e_lat);

                    //a la fin de rendre toute mon information valide je peut ensuite cree un TripRecord qui encapsule tout les donnees a l'aide d'un constructeur
                    TripRecord record = new TripRecord(data[1],data[4],pickup_loc,end_loc,tripDist);
                    //je prends data[1] et data[4] car dans le fichier donnees le nom "unnamed" se trouve a l'index 1 et pour data[4] le pikcup_dateTime ce retrouve a cette index, 
                    //et vue qu'ils sont deja des strings je n'ait pas besoin de faire du parsing
                    Cluster cluster = new Cluster(record);
                   
                    database.add(cluster); //j'ajoute l'objet de record que je viens de creer dans mon database (ArrayList<TripRecord>)
                }
                count++;
            }
            buffRead.close();
            
        }
        catch(IOException e){
            e.printStackTrace();
        }
        
        //how to check for information printing does work btw
        /*
        for (int i = 0; i <3; i++){
            System.out.println(database.get(i).getTripRecord().getUnnamed()+" ~ " +
                Float.toString(database.get(i).getTripRecord().getPickupLocation().getLatitude()) + " , " 
                + Float.toString(database.get(i).getTripRecord().getPickupLocation().getLongitude()));
        }
        */
        ////////////////////////////////////


        Cluster datasource=new Cluster();
        //Eps=3,MinPts=4
       // datasource.readMatrix(new File("/home/orisun/test/dot.mat"));
        //datasource.readRLabel(new File("/home/orisun/test/dot.rlabel"));
        //Eps=2.5,MinPts=4
        //DBScan ds=new DBScan();
        //int clunum=ds.dbscan(datasource.objects);
        //datasource.printResult(datasource.objects,clunum);
    }
       

}