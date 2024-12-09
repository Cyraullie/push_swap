# push_swap
ARG=$(python3 generator.py 100 1 1000); ./push_swap $ARG | wc -l

# submodule :
git submodule init
git submodule update
