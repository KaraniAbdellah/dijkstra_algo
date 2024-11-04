# dijkstra_algo



# Images


# Generate graph image

### Install Graphviz

``` bash
sudo apt-get install graphviz
```

<p>Graphviz is a tool that helps you create diagrams or graphs using text commands
You write a description of your graph, and Graphviz turns it into an image.
it generate image from DOT files.</p>

<br>
<b>Graphviz takes a DOT file and generates a PNG image (or other image formats) of the graph.</b>


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





