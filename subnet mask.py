ip = input("Enter IP address (e.g., 192.168.1.1): ")
prefix_length = int(input("Enter prefix length (e.g., 24 for /24 subnet): "))

# Calculate subnet mask
subnet_mask = (1 << 32 - prefix_length) - 1
subnet_mask = (subnet_mask << prefix_length) & 0xFFFFFFFF

# Format the subnet mask in decimal format
subnet_mask = ".".join(str((subnet_mask >> i) & 0xFF) for i in [24, 16, 8, 0])

print("Subnet Mask:", subnet_mask)