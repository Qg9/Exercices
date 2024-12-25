(**
   @param n le nombre de boites
   @param valeur la valeur du marché du jour
   @param boites le contenu de chaque boite
*)
let rec calc v boites =
  (** TODO Afficher, sur une ligne, un unique entier : le nombre de séries
  justes modulo $1,000,000,007$.  *)

        match boites with 
                | [] -> ()
                | h::q -> begin
                        calc v q;
                        calc v q
                end
;;

let () =
  let n = read_int () in
  let boites = read_line () |> fun x -> if x = "" then [] else String.split_on_char ' ' x |> List.rev_map int_of_string |> List.rev in
  let r = etal n valeur boites in
        Printf.printf "%i \n" r;;
