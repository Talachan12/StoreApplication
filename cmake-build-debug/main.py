import matplotlib.pyplot as plt

product_names = []
quantities = []
selling_prices = []

with open('./products.txt', 'r') as file:
    lines = file.readlines()

product_data = {}
for line in lines:
    line = line.strip()
    if line:
        key, value = line.split(': ')
        product_data[key] = value
    else:
        if 'Product name' in product_data and 'Quantity' in product_data:
            product_names.append(product_data['Product name'])
            quantities.append(int(product_data['Quantity']))
            selling_prices.append(int(product_data["Selling price"]))
        product_data = {}


plt.figure("Products Graph")
plt.bar(product_names, quantities, color='#9de19a', edgecolor='black')
plt.title('Products Quantity', fontsize=16)
plt.xlabel('Products', fontsize=10)
plt.ylabel('Quantity', fontsize=10)
plt.autoscale()
plt.grid(axis='y', linestyle='--', alpha=0.7)

plt.show()