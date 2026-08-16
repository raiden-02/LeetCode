class NumberContainers {
  private index_num: Map<number, number>;
  private num_index: Map<number, SortedSet>;

  constructor() {
    this.index_num = new Map();
    this.num_index = new Map();
  }

  change(index: number, number: number): void {
    if (this.index_num.has(index)) {
      const old_number = this.index_num.get(index)!;

      if (old_number !== number) {
        this.num_index.get(old_number)?.delete(index);

        if (this.num_index.get(old_number)?.isEmpty()) {
          this.num_index.delete(old_number);
        }
      }
    }

    this.index_num.set(index, number);

    if (!this.num_index.has(number)) {
      this.num_index.set(number, new SortedSet());
    }

    this.num_index.get(number)!.add(index);
  }

  find(number: number): number {
    return this.num_index.has(number) ? this.num_index.get(number)!.first() ?? -1 : -1;
  }
}


/**
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = new NumberContainers()
 * obj.change(index,number)
 * var param_2 = obj.find(number)
 */
