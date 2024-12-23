(**
   @param n le nombre de sous-marins
   @param m le nombre de critères
   @param criteres les critères de chaque sous-marin
*)
let rec minimumExclus m criteres =
        let length = List.length criteres in
        
        if length <= 1 then length else
        if m = 0 then (length mod 2) else(
                
        
        let (l0, l1) = List.fold_left (fun (l0,l1) el -> 
                let h::q = el in
                if h = 1 then (l0,q::l1) else (q::l0, l1)) ([],[]) criteres in
        
        (minimumExclus (m-1) l0) + (minimumExclus (m-1) l1)
);;

let () =
  let n = read_int () in
  let m = read_int () in
  let criteres = List.init n (fun _ -> read_line () |> fun x -> if x = "" then [] else String.split_on_char ' ' x |> List.rev_map int_of_string |> List.rev) in
 
  let r = minimumExclus m criteres in
  Printf.printf "%i \n" r;;




















