class SortedSet {
  private items: number[];

  constructor() {
    this.items = [];
  }

  private findInsertionIndex(value: number): number {
    let left = 0, right = this.items.length;

    while (left < right) {
        const mid = Math.floor((left + right) / 2);

        if (this.items[mid] < value) left = mid + 1;

        else right = mid;
    }

    return left;
  }

  add(value: number): void {
    if (!this.items.includes(value)) {
        this.items.splice(this.findInsertionIndex(value), 0, value);
    }
  }

  delete(value: number): void {
    const index = this.items.indexOf(value);
    
    if (index !== -1) {
      this.items.splice(index, 1);
    }
  }

  first(): number | undefined {
    return this.items[0];
  }

  isEmpty(): boolean {
    return this.items.length === 0;
  }
}
