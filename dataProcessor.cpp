#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//world                 - 10M
//china                 - 1M - http://geonames.nga.mil/gns/html/
//forestFire            - 700K - wildfire.cr.usgs.gov/firehistory/data.html
//clustering datasets   - http://cs.joensuu.fi/sipu/datasets/
//      - KDDCUP04Bio   - 145751 - the first 2 dimensions of a protein dataset with 145K entries
//      - MOPSI         - 13467 location records of users in Finland.
//      - Europe        - 169308 - differential coordinates of the map of Europe
//      - Birsch3       - 100k - random sized clusters in random locations

int main() {
    int count = 0;
    double a, b, c;
    string fileName;
    ifstream inFile;

    cout << "Enter FileLocation/FileName: ";
    cin >> fileName;

    ofstream newfile("output/"+fileName);

    inFile.open("src/"+fileName);
    if (!inFile) {
        cout << "Unable to open file " + fileName;
        exit(1); // terminate with error
    }

    while (inFile >> a >> b) {
        count = count + 1;
    }

    cout << "Lines : " << count << endl;

    inFile.close();

    inFile.open("src/"+fileName);
    if (!inFile) {
        cout << "Unable to open file src/" + fileName;
        exit(1); // terminate with error
    }

    while (inFile >> a >> b) {
        //cout << "Line = " << a << " : " << b << endl;
        newfile << a << " " << b << "\n";
    }
    
    inFile.close();
    newfile.close();

    //string simple = "/Volumes/bHd/simple-gps-points-120312.txt"
    // ofstream newfile ("/Volumes/bHd/gps-processed.txt");
    // if (newfile.is_open())
    // {
    //     for (Point p : points){
    //         newfile << p.x() << " " << p.y() << "\n";
    //     }
    //     newfile.close();
    // }
    // else cout << "Unable to open file";

    return EXIT_SUCCESS;
}
