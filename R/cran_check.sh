# before running this, update the version in this file and in the DESCRIPTION file (e.g., to 3.2.1)
rm multinet_3.2.tar.gz
find . -name "*.o" -type f -delete
cd multinet
rm -r src
./prepare.sh
cd ..
mv multinet/C++ .
mv multinet/prepare.sh .
R CMD build multinet
R CMD check --as-cran multinet_3.2.tar.gz
mv C++ multinet
mv prepare.sh multinet
