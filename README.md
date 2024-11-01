# dijkstra_algo



# Images


# Generate graph image

### Install Graphviz

``` bash
sudo apt-get install graphviz
```

This installs Graphviz, which includes the dot command necessary for generating images from DOT files.

### Install make2graph

``` bash
git clone https://github.com/lindenb/makefile2graph.git
cd make2graph
make
sudo cp make2graph /usr/local/bin/  # Move it to a directory in your PATH
```

### Update Your Makefile

``` bash
vis:
	make -Bnd | make2graph | dot -Tpng g.dot -o g.png
```

### Run Your Program

``` bash
make build    # This compiles your program
make vis      # This generates the graph image
```





