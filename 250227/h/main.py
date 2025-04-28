def main():
    # Read first line of input
    first_line = input().split()
    n = int(first_line[0])
    a = int(first_line[1])
    b = int(first_line[2])
    c = int(first_line[3])
    d = int(first_line[4])
    e = int(first_line[5])
    f = int(first_line[6])
    m = int(first_line[7])
    
    results = []
    for _ in range(m):
        q = int(input())
        
        # Calculate the four terms
        term1 = (a + b * q) ^ (c * q)
        term2 = (a + b * ((n - q) % n)) ^ (c * ((n - q) % n))
        term3 = (d + e * q) ^ (f * q)
        term4 = (d + e * ((n - q) % n)) ^ (f * ((n - q) % n))
        
        # Compute results
        y1 = (term1 + term2) / 2000.0
        y2 = (term3 - term4) / 2000.0
        y3 = (term3 + term4) / 2000.0
        y4 = -(term1 - term2) / 2000.0
        
        # Format to 6 decimal places
        results.append(f"{y1:.6f} {y2:.6f} {y3:.6f} {y4:.6f}")
    
    # Print all results
    print('\n'.join(results))

if __name__ == "__main__":
    main()