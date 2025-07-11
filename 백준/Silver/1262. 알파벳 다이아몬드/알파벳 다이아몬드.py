def solve_diamond_tiling(N, R1, C1, R2, C2):
    diamond_size = 2 * N - 1
    
    result = []
    
    for r in range(R1, R2 + 1):
        row = []
        for c in range(C1, C2 + 1):
            local_r = r % diamond_size
            local_c = c % diamond_size
            
            center = N - 1
            dr = abs(local_r - center)
            dc = abs(local_c - center)
            
            distance = dr + dc
            
            if distance > N - 1:
                row.append('.')
            else:
                alphabet_index = distance % 26
                row.append(chr(ord('a') + alphabet_index))
        
        result.append(''.join(row))
    
    return result

def main():
    line = input().strip()
    N, R1, C1, R2, C2 = map(int, line.split())
    
    result = solve_diamond_tiling(N, R1, C1, R2, C2)
    
    for row in result:
        print(row)

if __name__ == "__main__":
    main()