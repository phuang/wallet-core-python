# wallet-core-python
Python binding for wallet-core

# Build and install
```
# Checkout wallet-core-python
git clone https://github.com/phuang/wallet-core-python.git
cd wallet-core-python

# Checkout wallet-core submosule
git submodule init
git submodule update

# Build wallet-core
(cd wallet-core/; ./bootstrap.sh)

# Build wallet-core-python
python3 setup.py build

# Install wallet-core-python in $HOME directory
python3 setup.py install --prefix=~/.local

# Or install wallet-core-python in global python library directory
# sudo python3 setup.py install

```

# Generate python binding from wallet-core
This step is optional, the repository alreay includes generated python binding source code.
```
python3 codegen/generator.py
```

# Test
```
python3 ./demo/sample.py
```
