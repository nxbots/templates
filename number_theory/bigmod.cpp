ll bigmod(ll base, ll power, ll md) {
  if(power == 0) return 1;
  if(power % 2 == 1) {
    return ((base % md) * bigmod(base, power-1, md)) % md;
  }
  else {
  	ll y = bigmod(base, power/2, md);
    return (y * y) % md;
  }
}

//or	

ll bigmod(ll base, ll power,ll md){if(power==0) return 1;if(power%2==1){ return ((base%md)*bigmod(base,power-1,md))%md;} else {ll y=bigmod(base,power/2,md);return (y*y)%md;}}
